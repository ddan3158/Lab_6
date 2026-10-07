#pragma once
#include "student.h"

namespace YooDaeun2693185
{
    class studentStatus
    {
        Student s;
        bool status;
        public:
            studentStatus (Student testS = Student{6767676, 70, 'C'}, bool testStatus=false)
            :s{testS}, status{testStatus}
            {}

    void print() const{
        s.print(); //student::print()
        if(status){
            std::cout<<"on school!\n";
        }
        else{
            std::cout<<"NOT on school.\n";
        }
    }
    const Student& getstudent() const{return s;}
    void setstudent(const Student& testS){s=testS;}
    };
}