//
// Created by root on 19-2-14.
//

#ifndef MYODB_MYODB_H
#define MYODB_MYODB_H


#include <string>

#include <odb/core.hxx>
#include <odb/nullable.hxx>

#pragma db object
class student{
public:
    student(std::string name,std::string sscholl, unsigned short age):name(name),sscholl(sscholl),age_(age){}
    student(std::string name,std::string likes,std::string sscholl, unsigned short age):name(name),sscholl(sscholl),likes(likes),age_(age){}
    const std::string& get_name() const {
        return name;
    }
    const odb::nullable<std::string>& get_likes()const{
        return likes;
    }
    const std::string& get_sscholl()const{
        return sscholl;
    }
    const unsigned short get_age(){
        return age_;
    }
    void age(unsigned short age){
        age_ = age;
    }
private:
    friend class odb::access;

    student () {}

#pragma db id auto
    unsigned long id_;

    std::string name;
    odb::nullable<std::string> likes;
    std::string sscholl;
    unsigned short age_;
};

#endif //MYODB_MYODB_H
