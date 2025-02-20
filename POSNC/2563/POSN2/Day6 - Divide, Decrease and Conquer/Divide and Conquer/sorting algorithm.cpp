#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int n=95;
typedef high_resolution_clock Clock;
typedef Clock::time_point ClockTime;
int* generate_input(int n){
    int* generated_input = (int*) malloc(n*sizeof(int));
    int c, r;
    for (int i=0;i<n;i++) {
        c = rand()%10 + 1;
        r = rand() % (2*n) + 1;
        if (c > 5) generated_input[i] = r;
        else generated_input[i] = -r;
    }
    return generated_input;
}
void Merge(int *a,int p,int q,int r){
    int n1=q-p+1,n2=r-q;
    int i,j;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=a[p+i];
    for(j=0;j<n2;j++)
        R[j]=a[q+j+1];
    i=j=0;
    int k=p;
    while (i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }

}
void merge_sort(int* a, int p,int r){
    if(p<r){
    int q=(p+r)/2;
    merge_sort(a,p,q);
    merge_sort(a,q+1,r);
    Merge(a,p,q,r);
    }
}
void insertion_sort(int* a, int n){
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
void print_array(int* a, int n){
    for (int i=0; i<n ; i++) cout << a[i] << ",";
    cout << endl;
}
void swap(int *a,int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
int pivot(int *a,int l,int r){
    int p=a[l];
    int i=l+1,j=r;
    while(i<j){
        while(a[i]<p)
            i++;
        while(a[j]>p)
            j--;
        swap(&a[i],&a[j]);
    }
    print_array(a,n);
    swap(a[i],a[j]);
    if(a[l]>a[j])
        swap(a[l],a[j]);
    return j;
}
void quick_sort(int *a,int l,int r){
    if(l<r){
        int s=pivot(a,l,r);
        quick_sort(a,l,s-1);
        quick_sort(a,s+1,r);
    }
}
bool check_sorted_array(int* a, int n){
    // return true if the list is sorted, false otherwise.
    for (int i=1; i<n ; i++) if (a[i-1] > a[i]) return false;
    return true;
}


int main(){
   // int n=50;
    int* input_original = generate_input(n);

    int* input_insertion = (int*) malloc(n*sizeof(int));
    int* input_merge     = (int*) malloc(n*sizeof(int));
    int* input_quick     = (int*) malloc(n*sizeof(int));

    for (int i=0;i<n;i++) input_insertion[i] = input_merge[i] =input_quick[i] = input_original[i];

    print_array(input_original, n);

    char is_sorted_insertion = check_sorted_array(input_insertion, n) ? 'Y' : 'N';
    char is_sorted_merge = check_sorted_array(input_merge, n) ? 'Y' : 'N';
    char is_sorted_quick = check_sorted_array(input_quick, n) ? 'Y' : 'N';


    printf("\nIs insertion_input sorted? %c\n", is_sorted_insertion);
    printf("Is merge_input sorted? %c\n", is_sorted_merge);
    printf("Is quick_input sorted? %c\n", is_sorted_quick);


    // Example code for timing ...

    ClockTime start_time = Clock::now();
    insertion_sort(input_insertion, n);
    ClockTime end_time = Clock::now();

    double execution_time_sec = duration_cast<chrono::nanoseconds>(end_time - start_time).count();
    cout << "Insertion sort takes " << setprecision(5) << execution_time_sec*1e-9 << " seconds" << endl;


    start_time = Clock::now();
    merge_sort(input_merge,0,n-1);
    end_time = Clock::now();

    execution_time_sec = duration_cast<chrono::nanoseconds>(end_time - start_time).count();
    cout << "Merge sort takes " << setprecision(5) << execution_time_sec*1e-9 << " seconds" << endl;

    start_time = Clock::now();
    quick_sort(input_quick,0,n-1);
    end_time = Clock::now();

    execution_time_sec = duration_cast<chrono::nanoseconds>(end_time - start_time).count();
    cout << "Quick sort takes " << setprecision(5) << execution_time_sec*1e-9 << " seconds" << endl;


    is_sorted_insertion = check_sorted_array(input_insertion, n) ? 'Y' : 'N';
    is_sorted_merge = check_sorted_array(input_merge, n) ? 'Y' : 'N';
    is_sorted_quick = check_sorted_array(input_quick,n) ? 'Y' : 'N';

    printf("\n### After running the sort algorithms ###\n\n");
    printf("Is insertion_input sorted? %c\n", is_sorted_insertion);
    printf("Is merge_input sorted? %c\n", is_sorted_merge);
    printf("Is quick_input sorted? %c\n\n", is_sorted_quick);

    print_array(input_insertion, n);
    print_array(input_merge, n);
    print_array(input_quick, n);

    return 0;
}
