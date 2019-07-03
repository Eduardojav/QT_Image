#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include<iostream>
#include"image.h"
#include<direct.h>
#include <QDebug>

using namespace std;

template<class T>
class linked_list{
    public:
    struct node{
        T date;
        node* p_next;
        node* p_prev;
        node(const T &d,node* n=NULL,node* m=NULL){
            date=d;
            p_next=n;
            p_prev=m;
        }
    };

    private:
        node* p_head;
        node* p_end;

    public:
        node* n;
        //node aux;
        linked_list():p_head(NULL),p_end(NULL),n(NULL){
        /*    Image a;
            node axu(a,NULL,NULL);
            aux=axu;
        */
        }
        ~linked_list(){
            while(p_head){
                remove_front();
            }
        }

        void push_front(T&d){
            node* p_aux=p_head;
            p_head=new node(d,p_head,NULL);
            if(p_aux==NULL){
                p_end=p_head; //cuando inicie con push_front
                n=p_head;
            }
            else if(p_aux->p_prev==NULL){
                p_aux->p_prev=p_head;
            }
            n=p_head;
        }

        void push_back(const T &d){
            qDebug()<<"1";
            node* p_aux=p_end;
            qDebug()<<"2";
            p_end=new node(d,NULL,p_end);
            qDebug()<<"3";
            if(p_aux==NULL){
                p_head=p_end; //cuando inicie con push_back
                qDebug()<<"4";
                n=p_end;
            }
            else if(p_aux->p_next==NULL){
                qDebug()<<"4.2";
                p_aux->p_next=p_end;
            }
            qDebug()<<"5";
            n=p_head;
        }

        void remove_front(){
            if(!p_head) return;
            node* del=p_head;
            p_head=p_head->p_next;
            delete del;
        }
        class iterator{
            private:
                node* m;
            public:
                iterator(node* _m=NULL){
                    m=_m;
                }
                ~iterator(){}

                T& operator*(){	//contenido
                    return m->date;
                }
                node*& nod(){
                    return m;
                }
                iterator& operator ++(){	//siguiente
                    m=m->p_next;
                    return *this;
                }
                bool operator !=(const iterator& it){
                    return m!=it.m;
                }
            };

        void remove(int posic){
            int j=posic-2;
            int i=0;
            linked_list<string>::iterator it;
            node* p_aux;
            node* del;
            node* m=p_head;
            while(i!=posic){
                if(i==j){
                    p_aux=m;
                }
                if(i==j+1){
                    del=m;
                }
                m=m->p_next;
                i++;
            }
            p_aux->p_next=m;
            m->p_prev=p_aux;
            delete del;
        }
        iterator now(){
            return iterator(n);
        }

        iterator begin(){
            return iterator(p_head);
        }
        iterator ult(){
            return iterator(p_end);
        }
        iterator end(){
            return iterator(NULL);
        }
        iterator position(string a){
            if(a=="next"){
                n=n->p_next;
                if(n==NULL){
                    n=p_head;
                }
            }
            else if(a=="prev"){
                n=n->p_prev;
                if(n==NULL){
                    n=p_end;
                }
            }
            return iterator(n);
        }
};



#endif // LINKED_LIST_H
