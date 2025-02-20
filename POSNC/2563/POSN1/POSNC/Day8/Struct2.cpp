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
	STD newest,stdrecord[5]={{10001 ,"Chris Hemsworth",{11,12,2552},{3,5,2560},4},
					{10002,"Tom Cruise",{11,12,2552},{3,5,2560},4},
					{10003,"Taylor Swift",{13,12,2552},{1,5,2560},2},
					{10004,"Hugh Grant",{9,9,2551},{1,5,2560},1},
					{10005,"Kristen Stewart",{9,4,2552},{7,5,2560},1}
					};
	newest=stdrecord[0];
	for(i=1;i<5;i++){
		if(stdrecord[i].std_checkin.year>newest.std_checkin.year){
			newest=stdrecord[i];
		}
		else if(stdrecord[i].std_checkin.year==newest.std_checkin.year){
				if(stdrecord[i].std_checkin.month>newest.std_checkin.month){
					newest=stdrecord[i];
				}
				else if(stdrecord[i].std_checkin.month==newest.std_checkin.month){
						if(stdrecord[i].std_checkin.day>newest.std_checkin.day)
							newest=stdrecord[i];
				}
		}
	}
	printf("id    name\t\tbirth\t\tcheckin\t     room\n");
	printf("%d ",newest.std_id);
	printf("%s\t", newest.std_name);
	printf("%-3d", newest.std_birth.day );
	printf("%-3d ", newest.std_birth.month );
	printf("%-6d ", newest.std_birth.year);
	printf("%-3d ", newest.std_checkin.day );
	printf("%-3d ", newest.std_checkin.month );
	printf("%-6d ", newest.std_checkin.year);
	printf("%d\n", newest.room);
}
