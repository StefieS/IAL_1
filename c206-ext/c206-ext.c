/*
 *  Předmět: Algoritmy (IAL) - FIT VUT v Brně
 *  Rozšíření pro příklad c206.c (Dvousměrně vázaný lineární seznam)
 *  Vytvořil: Daniel Dolejška, září 2024
 */

#include "c206-ext.h"

bool error_flag;
bool solved;

/**
 * Tato metoda simuluje příjem síťových paketů s určenou úrovní priority.
 * Přijaté pakety jsou zařazeny do odpovídajících front dle jejich priorit.
 * "Fronty" jsou v tomto cvičení reprezentovány dvousměrně vázanými seznamy
 * - ty totiž umožňují snazší úpravy pro již zařazené položky.
 * 
 * Parametr `packetLists` obsahuje jednotlivé seznamy paketů (`QosPacketListPtr`).
 * Pokud fronta s odpovídající prioritou neexistuje, tato metoda ji alokuje
 * a inicializuje. Za jejich korektní uvolnení odpovídá volající.
 * 
 * V případě, že by po zařazení paketu do seznamu počet prvků v cílovém seznamu
 * překročil stanovený MAX_PACKET_COUNT, dojde nejdříve k promazání položek seznamu.
 * V takovémto případě bude každá druhá položka ze seznamu zahozena nehledě
 * na její vlastní prioritu ovšem v pořadí přijetí.
 * 
 * @param packetLists Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 * @param packet Ukazatel na strukturu přijatého paketu
 */
void receive_packet( DLList *packetLists, PacketPtr packet ) {
	DLL_First(packetLists);
	
	// If list is empty insert first
	if (!DLL_IsActive(packetLists)) {
		QosPacketListPtr newEle = malloc(sizeof(QosPacketList));
		if (newEle == NULL) {
			return;
		}
		newEle->list = malloc(sizeof(DLList));
		if (newEle->list == NULL) {
			free(newEle);
			return;
		}
		DLL_Init(newEle->list);
		newEle->priority = packet->priority;
		DLL_InsertFirst(newEle->list, (long) packet);
		DLL_InsertFirst(packetLists, (long) newEle);
		
	}
	
	// If list is not empty check for priority 
	while (DLL_IsActive(packetLists)) {
		QosPacketListPtr activeEle = ((QosPacketListPtr)packetLists->activeElement->data);

		if (activeEle->priority > packet->priority) {
			DLL_Next(packetLists);
			continue;
		}
		
		if (activeEle->priority == packet->priority) {
	
			DLL_InsertLast(activeEle->list, (long) packet);
			if (activeEle->list->currentLength > MAX_PACKET_COUNT) {
				DLL_First(activeEle->list);
				while (DLL_IsActive(activeEle->list)) {
					DLL_DeleteAfter(activeEle->list);
					DLL_Next(activeEle->list);
				}
			}

			break;
		}
		
		if (activeEle->priority < packet->priority) {
			QosPacketListPtr newEle = malloc(sizeof(QosPacketList));
			if (newEle == NULL) {
				return;
			}
			newEle->list = (DLList *) malloc(sizeof(DLList));
			if (newEle->list == NULL) {
				free(newEle);
				return;
			}
			newEle->priority = packet->priority;
			DLL_Init(newEle->list);
			DLL_InsertFirst(newEle->list, (long) packet);
			if (DLL_IsActive(packetLists)) {
                DLL_InsertBefore(packetLists, (long)newEle);
            } else {
                DLL_InsertLast(packetLists, (long)newEle);
            }
			break;
		}
		
	}

}

/**
 * Tato metoda simuluje výběr síťových paketů k odeslání. Výběr respektuje
 * relativní priority paketů mezi sebou, kde pakety s nejvyšší prioritou
 * jsou vždy odeslány nejdříve. Odesílání dále respektuje pořadí, ve kterém
 * byly pakety přijaty metodou `receive_packet`.
 * 
 * Odeslané pakety jsou ze zdrojového seznamu při odeslání odstraněny.
 * 
 * Parametr `packetLists` obsahuje ukazatele na jednotlivé seznamy paketů (`QosPacketListPtr`).
 * Parametr `outputPacketList` obsahuje ukazatele na odeslané pakety (`PacketPtr`).
 * 
 * @param packetLists Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 * @param outputPacketList Ukazatel na seznam paketů k odeslání
 * @param maxPacketCount Maximální počet paketů k odeslání
 */
void send_packets( DLList *packetLists, DLList *outputPacketList, int maxPacketCount ) {
	DLL_First(packetLists);
	int i = 0;
	while(DLL_IsActive(packetLists) && i < maxPacketCount) {
		DLList *list = ((QosPacketListPtr)packetLists->activeElement->data)->list;
		DLL_First(list);
		while (DLL_IsActive(list) && i < maxPacketCount) {
			DLL_InsertLast(outputPacketList, list->activeElement->data);
			DLL_DeleteFirst(list);
			DLL_Next(list);
			i++;
		}
		DLL_Next(packetLists);
	}
}
