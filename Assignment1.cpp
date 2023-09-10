#include <iostream>
#include <cstring>

using namespace std;

struct student{
    int Rollno;
    char name[20];
    float per;
};

void create_database(student[],int);
void display_database(student[],int);
void bubble_sort(student[],int);
int liner_search(student[],int,int);
int binary_search(student[],int,int,char[] );

void create_database(student s[20],int n){
    int i;
    for(i = 0; i <n; i++){
    cin>>s[i].Rollno>>s[i].name>>s[i].per;
    cout<<"\n";
    }
}

void display_database(student s[20],int n){
   int i;
   for(i = 0; i <n; i++){
   cout<<"\t"<<s[i].Rollno<<"\t"<<s[i].name<<"\t"<<s[i].per<<"\n";
    }
}

void bubble_sort(student s[20],int n){ 
   int i,j;
   student temp;
   for(i=0; i<n;i++){
       for(j=0;j<n-i-1;j++){
       if (s[j].Rollno>s[j+1].Rollno){
           temp = s[j];
           s[j] = s[j+1];
           s[j+1] = temp;
       }
       }
   }
}

int liner_search(student s[20] ,int n ,int x){
   int i;
   for(i=0;i<n;i++){
       if(s[i].Rollno==x){
       break;
       }  
   }
   return i;
}


int binary_search(student s[20],int l,int u, char x[] ){
   int mid;
   while(l<u){
      mid = (l+u)/2;
      
      if(strcmp(s[mid].name,x)==0){
          break;
      }else if(strcmp(s[mid].name,x) > 0){
          u = mid-1;
      }else{
          l = mid+1;
      }
   }
   return mid;
   
}


int main(){
    int ch,ch1,n,x,i;
    student s[20];
    char name[20];
    cout<<"\n Enter the number of Enrollment :";
    cin>>n;
    
    do{
    
    cout<<"\n 1. Create Database";
    cout<<"\n 2. Display Database";
    cout<<"\n 3. Bubble sort";   
    cout<<"\n 4. Linear search";  
    cout<<"\n 5. Binary search \n";     
    
    cin>> ch;
    
    switch(ch){
        case 1: create_database(s,n);
                break;
                
        case 2: display_database(s,n);
                break;        
                
        case 3: bubble_sort(s,n);
                break;
                
        case 4: cout<<"\n Enter the Roll number :";
                cin>>x;
                i=liner_search(s,n,x);
                cout<<"Roll number is found at place:"<<i+1;
                break;
         
        case 5: cout<<"\n Enter the Name :";
                cin>>name;
                i=binary_search(s,0,n-1,name);
                cout<<"Roll number found at place:"<<i+1;
                break;        
                        
    }
    cout<<"\n Do you want to continue \n";
    cin>>ch1;
         
    }while(ch1<=5);

}
 