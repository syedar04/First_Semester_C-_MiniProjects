#include <iostream>
#include <cmath>
using namespace std;

//This works for only 10 values in an array but it can be modified to work for any N number of elements (considering the element limit for arrays)


//Gets input from user for the array
void inp_arr(float arr[]){
    for(int i = 0; i < 10; i++)
    cin >> arr[i];
}

//Calculates Standard Deviation
float std_dev(float arr[], float avg){
    float sum = 0, std_dev; 
    for(int i = 0; i < 10;i++){
        sum += (arr[i] - avg) * (arr[i] - avg);
    }
    std_dev = sum / (10);
    return sqrt(std_dev);
}

//Sorts the array (No use of it in the calculations it was just part of the question)
void sort(float arr[]){
    int temp;
    for(int i = 0; i < 9 ; i++){
        for(int j = i + 1; j < 10; j++){
            if(arr[i] < arr[j]){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            }
        }
    }
}


//Calculating the averae of the values in the array
float avgvalue(float arr[]){
    float sum = 0, average = 0;
    for(int i = 0; i < 10; i++){
        sum += arr[i];
    }
    average = sum / 10;
    return average;
}


//Calculates the percent of data within the first standard deviation
void percentage(float arr[],float avg, float stdev){
    float count = 0;
    float percentage;
    for(int i = 0; i < 8; i++){
        if(arr[i] > (avg - stdev) && arr[i] < (avg + stdev))
        count++;
    }
    percentage = (count/10) * 100;
    cout << endl << "Percentage of data with in 1st standard deviation is: " << percentage << "%";
     if(percentage >= 65 && percentage <= 75)
     cout << endl << "Good Bell Shape";
     else
     cout << endl <<  "Bad Bell Shape";
}

//Driver Code
int main(){
    float arr[10];
    inp_arr(arr);
    sort(arr);
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
   cout << endl << "Avg: " << avgvalue(arr);
   cout << endl << "Standard Deviation: " << std_dev(arr,avgvalue(arr));
   float avg = avgvalue(arr); float std = std_dev(arr,avg);
    percentage(arr,avg,std);
}
