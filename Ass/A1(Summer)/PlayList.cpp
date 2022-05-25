// Write your name and date here
#include "PlayList.h"

PlayList::PlayList(): head(NULL), tail(NULL), elementCount(0){

}

void PlayList:: insert(Song sng, unsigned int pos){
   
    PlayListNode * newNode = new PlayListNode(sng, NULL);
    PlayListNode * current = head;

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else if(pos == 0){
        current->next = head;
        head = current;
    }
    else{
        for(int i=0; i<pos; i++){
            if(current != NULL){
                current = current->next;
            }
        }
        newNode->next = current->next;
        current->next = current;
    }
    elementCount++;
}

// PRE: 0 <= pos <= length of list-1
// PARAM: pos - 0-based position of element to be removed and returned
// POST: Song at position pos is removed and returned
Song Song:: remove(unsigned int pos){
   playListNode * current = head;
   playListNode * remNode = NULL;
   
   if(pos = 0){
      head = current->next;
      elementCount--;
      return current->song;
    }
   else{
      for(int i=0; i<pos; i++){
         current = current->next;
      }
      remNode = current->next;
      current->next = remNode->next;
      eleemtnCount--;
      return remNode->song;
   }
}
   
// PRE: 0 <= pos1, pos2 <= length of list-1
// PARAM: pos1, pos2 - 0-based positions of elements to be swapped
// POST: Songs at positions pos1 and pos2 are swapped
void swap(unsigned int pos1, unsigned int pos2);

// Accessor
// PRE: 0 <= pos <= length of list-1
// PARAM: pos - 0-based position of element to be removed and returned
// POST: returns the Song at position pos
Song get(unsigned int pos) const{
   playListNode * current = head;
   for(int i=0; i<=pos; i++){
      current = current->next;
   }
   return current->song;
}

// POST: returns the number of songs in the PlayList
unsigned int size() const{
   return elementCount;
}


// PlayList method implementations go here
