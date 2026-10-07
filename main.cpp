#include "student.h"

namespace YooDaeun2693185{
    void printStudentArray(const Student a[], const int n){
        for (int i=0; i<n; i++)
        std::cout<<a[i]<<std::endl;
    }
}


int main(){
    using namespace YooDaeun2693185;
    
    const int n{4};
    Student a[n];

    a[0]=Student{"Kim Mama", 1112222, 100, 'A'};
    a[1].setname("Lee Lala");
    a[1].setID(3334444);
    a[1].setscore(90);
    a[1].setgrade('B');
    a[2].input();
    std::cin>>a[3];
    printStudentArray(a,n);

    std::array<Student, n> arr;
    for (int i=0; i<arr.size(); ++i){//size=i<n
        arr.at(i)=a[i];//=arr[i]=a[i];
    }
    for (const auto& arri: arr){
        arr.print();
    }

    return 0;
}