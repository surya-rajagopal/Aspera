#include "trie.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct trieNodeTag {
char key;
trieVal value;
struct trieNodeTag *next;
struct trieNodeTag *children;
}trieNodeT;


typedef struct trieCDT {
 trieNodeT *root;
}trieCDT;

trieADT TrieCreate();
void TrieAdd(struct trieNodeTag**, char*,int);
int TrieisMember(trieADT, char[]);

void main(void)
{
 trieADT trie;
 trie = TrieCreate();
 trie->root = (trieNodeT *) malloc(sizeof(struct trieNodeTag));
 trie->root->key = '.';
 trie->root->next = NULL;
 trie->root->children = NULL;
 TrieAdd(&trie->root, "Divya", 25);
 printf("\n root key %c \n",trie->root->key);
 printf("\n a key is %c \n",trie->root->children->key);
 TrieAdd(&trie->root, "Divya", 29);
 TrieAdd(&trie->root, "Dimple", 46);
 TrieAdd(&trie->root, "Dimple", 33);
 //TrieisMember(trie, "Katrina");
 TrieisMember(trie, "Dimple");
 return;
}

trieADT TrieCreate()
{
 trieADT trieStr = (trieADT )malloc(sizeof(struct trieCDT));
 return trieStr;
}


trieNodeT* searchCharNext(trieNodeT *nextPtr, char s)
{
 if(nextPtr == NULL)
  {
   return NULL;
  }
 
printf("key is %c \n",nextPtr->key);
printf("s is %c \n",s);
 if(nextPtr->key == s)
    return nextPtr;
 
  while(nextPtr->next != NULL)
  {
    if(nextPtr->next->key == s)
      return nextPtr->next;
     nextPtr = nextPtr->next;
  } 
  
  return nextPtr;
}


void TrieAdd(struct trieNodeTag **root , char *string, int value)
{
 int i = 0;
 trieNodeT *node;
 trieNodeT *currNode;
 if(*root == NULL || string == NULL)
  return;
  
 currNode = (*root);
 //node = currNode;

 while(string[i] != '\0')
 {
   if((node = searchCharNext(currNode->children,string[i])) == NULL)
  {
    currNode->children = (trieNodeT *) malloc(sizeof(struct trieNodeTag));
    printf("\n a new node has been created as the first child \n");
    currNode->children->key = string[i];
    currNode = currNode->children;
    printf("currnodes key is %c \n",currNode->key);
  } 
   else
  {
     if(node->key == string[i])
    {
     printf("\n node already found \n");
     currNode = node;
    }
     else
    { 
     printf("a new node added in the next feild \n");
     node->next = (trieNodeT *) malloc(sizeof(struct trieNodeTag));
     node->next->key = string[i];
     currNode = node->next;
    }
    
  } 
  printf("iterating over \n");
  i++;
 }
 currNode->children = (trieNodeT *) malloc(sizeof(struct trieNodeTag));
 currNode->children->key = '\0';
 currNode->children->value = value;
} 


int TrieisMember(trieADT trie, char keys[])
{
  trieNodeT *currNode;
  trieNodeT *code;
  int i = 0;
  if(trie == NULL || trie->root == NULL || trie->root->children == NULL)
    return 0;
  int found;
  
  currNode = trie->root->children;

  for(; ;)
  {
       for(code=currNode;code != NULL; code = code->next)
      {
        if(code->key == keys[i])
        {
          break;     
        }
      }
     
      if(code == NULL)
        return 0; 
       if(keys[i] == '\0')
      {
       printf("word found in trie !!!\n");
       return 1;
      }     
     i++;
     currNode = code->children;
  }
}



