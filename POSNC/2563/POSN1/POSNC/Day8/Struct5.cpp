#include <stdio.h>
int main(){
	int i;
	typedef struct student STD;
	typedef struct date DATE;
	struct date{
		int day;
		int month;
		int year;
	}
	DATEstd_birth,std_checkin;
	struct student{
		int std_id;
		char std_name[40];
		struct date std_birth;
		struct date std_checkin;
		int room;
	};
	STD stdrecord[5]={{10001 ,"Chris Hemsworth",{11,12,2552},{3,5,2560},4},
					{10002,"Tom Cruise",{11,12,2552},{3,5,2560},4},
					{10003,"Taylor Swift",{13,12,2552},{1,5,2560},2},
					{10004,"Hugh Grant",{9,9,2551},{1,5,2560},1},
					{10005,"Kristen Stewart",{9,4,2552},{7,5,2560},1}
					};
	printf("id    name\t\t   age\n");		
	for(i=0;i<5;i++){
		printf("%d ",stdrecord[i].std_id);
		printf("%s\t", stdrecord[i].std_name);
		printf("%5d\n", 2564-stdrecord[i].std_birth.year );
	}
}
