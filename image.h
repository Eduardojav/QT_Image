#ifndef IMAGE_H
#define IMAGE_H
#include<iostream>
#include<string>
#include<dirent.h>

using namespace std;

class Image{
    private:
        string name;
        string path;
        string* labels=new string[30];

    public:
    Image(string _name=" ",string _path=" ",string* _label=NULL):name(_name),path(_path),labels(_label){
        if(_label!=NULL){
            int i=0;
            while( _label[i] != "\0" ){
                labels[i]=_label[i];
                i++;
            }
        }
    }
    ~Image(){

    }

    Image& operator =(const Image& a){
        name=a.date_name();
        path=a.date_path();
        labels=a.date_label();
        return *this;
    }

    string date_name()const{
        return name;
    }
    string date_path()const{
        return path;
    }
    string* date_label()const{
        return labels;
    }

};


#endif // IMAGE_H
