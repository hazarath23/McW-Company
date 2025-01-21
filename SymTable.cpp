#include<string.h>
#include<iostream>
#include <stdint.h>
using namespace std; 
struct symTable
{
    string k;
    int value;
    struct symTable* next;
};
typedef struct symTable* SymTable_t;
SymTable_t head,tail=NULL;
SymTable_t SymTable_new (void)
{
    SymTable_t p = (SymTable_t)malloc(sizeof(SymTable_t));
    p->k="";
    p->value=0;
    p->next=NULL;
    return p;
}
void SymTable_free (SymTable_t oSymTable)
{
    SymTable_t p;
    while(oSymTable!=NULL)
    {
        p=oSymTable;
        oSymTable=oSymTable->next;
        free(p);
    }
}
int SymTable_getLength (SymTable_t oSymTable)
{
    int len=0;
    while(oSymTable!=NULL)
    {
        len+=1;
        oSymTable=oSymTable->next;
    }
    return len;
}
int SymTable_contains (SymTable_t oSymTable,const char *pcKey)
{
    while(oSymTable!=NULL)
    {
        if(oSymTable->k==pcKey)
        return 1;
        oSymTable=oSymTable->next;
    }
    return 0;
}
int SymTable_put (SymTable_t oSymTable,const char *pcKey,const void *pvValue)
{
    if(head==NULL&&tail==NULL)
    {
        SymTable_t t = SymTable_new();
        t->k = pcKey;
        t->value = (uintptr_t) pvValue;
        head=tail=NULL;
    }
    else
    {
        if(SymTable_contains(head,pcKey))
        {
            return 0;
        }
        else
        {
            SymTable_t t = SymTable_new();
            t->k = pcKey;
            t->value = (uintptr_t) pvValue;
            head=tail=NULL;
            tail->next=t;
            tail=tail->next;
            return 1;
        }
    }
}
void *SymTable_replace (SymTable_t oSymTable,const char *pcKey,const void *pvValue)
{
    while(oSymTable!=NULL)
    {
        if(oSymTable->k==pcKey)
        {
            int f = oSymTable->value;
            oSymTable->value=(uintptr_t)pvValue;
            return (void*)(uintptr_t)f;
        }
    }
    return (void*)NULL;
}
void *SymTable_get (SymTable_t oSymTable, const char *pcKey)
{
    while(oSymTable!=NULL)
    {
        if(oSymTable->k==pcKey)
        {
            return (void*)(uintptr_t)oSymTable->value;
        }
        oSymTable=oSymTable->next;
    }
    return (void*)NULL;
}
void *SymTable_remove (SymTable_t oSymTable,const char *pcKey)
{
    if(oSymTable->k==pcKey)
    {
        SymTable_t p = head;
        head=head->next;
        free(p);
    }
    else
    {
        while((oSymTable->next)->k!=pcKey)
        {
            oSymTable=oSymTable->next;
            if(oSymTable->next==NULL)
            {
                return NULL;
            }
        }
        SymTable_t p = oSymTable->next;
        oSymTable->next = p->next;
        void* kr = (void*)(uintptr_t) p->value;
        free(p);return kr;
    }
}
void SymTable_map (SymTable_t oSymTable,void (*pfApply) (const char *pcKey,const void *pvValue, void *pvExtra),const void *pvExtra)
{
    while(oSymTable!=NULL)
    {
        pfApply((char*)oSymTable->k,(void*)oSymTable->value,pvExtra);
    }
}
int main()
{
    cout<<"Hello how are you?"<<"\n";
    return 0;
}