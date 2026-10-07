#include <iostream>
#pragma once
#include <string>

namespace YooDaeun2693185{

    class Student{
         std::string name{};
         int ID;
         int score;
         char grade;
        void testID(){
            if((ID)<1000000||(ID)>9999999){
                std::cout<<"Wrong ID.\n";
                std::exit(1);
            }
        }
        void testscore(){
            if((score)<0||(score)>100){
                std::cout<<"Wrong Score.\n";
                std::exit(1);
            }
        }
        void testgrade(){
            if((grade)<'A'||(grade)>'F'){
                std::cout<<"Wrong grade.\n";
                std::exit(1);
            }
        }

     public:
        Student(const std::string& n="NO name yet", int I=1234567, int s=0, char g='F')
        :name{n}, ID{I}, score{s}, grade{g}
        {
            testID(); testscore(); testgrade();
        }
        void input(){
            std::cout<<"enter name: ";
            std::getline(std::cin>>std::ws, name);//std::cin>>name;//>>std::ws줄바꿈 무시
            std::cout<<"enter ID: ";
            std::cin>>ID; testID();
            std::cout<<"enter score: ";
            std::cin>>score; testscore();
            std::cout<<"enter grade: ";
            std::cin>>grade; testgrade();
        }
        friend std::istream& operator>>(std::istream& is, Student& s){
            std::cout<<"Enter name: ";
            std::getline(is>> std::ws, s.name);
            std::cout<<"Enter ID: ";
            is>>s.ID; s.testID();
            std::cout<<"Enter Score: ";
            is>>s.score; s.testscore();
            std::cout<<"Enter Grade: ";
            is>>s.grade; s.testgrade();
            return is;}//input의 std::cin을 is로

        void print() const{
            std::cout<<name<<" ("<<ID<<")"<<", "<<score<<", "<<grade<<"\n";
        };
        friend std::ostream& operator<<(std::ostream& os, const Student& s){
            os<<s.name<<" ("<<s.ID<<")"<<", "<<s.score<<", "<<s.grade<<"\n";
            return os;
        }
        void setname(const std::string& n){name=n;}
        void setID(int newID){
            ID=newID;
            testID();
        }
        void setscore(int newscore){
            score=newscore;
            testscore();
        }
        void setgrade(int newgrade){
            grade=newgrade;
            testgrade();
        }
       const std::string getline() const{
            return name;
        }
        int getID() const{
            return ID;
        };
        int getscore() const{
            return score;
        };
        char getgrade() const{
            return grade;
        };
        //전위증가연산자
        //intPair: x, y //intPair a;  a++; //x++, y++
        //Student s; s++; //++score
        Student operator++(){
            return Student{name, ID, ++score, grade};}
        //후위증가연산자
        Student operator++(int){
            Student temp{name, ID, score, grade};
            score++;
            return temp;
        }
        //이항연산자 ==, 이항연산자 + 정의
        friend bool operator==(const Student& s1, const Student& s2){
            return s1.ID == s2.ID;
        }
        friend int operator+(const Student& s1, const Student& s2){
            return s1.score + s2.score;
        }
    };
}
