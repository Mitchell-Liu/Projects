// Write your name and date here
#include "PlayList.h"

PlayList::PlayList(): head(NULL), tail(NULL) {

}

void PlayList:: insert(Song sng, unsigned int pos){
   
    PlayListNode * newNode = new PlayListNode(sng, NULL);
    PlayListNode * current = head;

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else if(pos == elementCount){
        tail->next = newNode;
        tail = newNode;
    }
    else{
        for(int i=0; i<pos; i++){
            if(current != NULL){
                current = current->next;
            }
        }
    }
}
// PlayList method implementations go here