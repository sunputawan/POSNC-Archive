#include <stdio.h>
int main(){
	float score, grade;
	printf("How much score do you get?: ");
	scanf("%f", &score);
	if(score>100)
		printf("The score must not be more than 100.");
	else	if(score>=80)
	{
		 		grade=4.00;
		 		printf("You have got %f", grade);
	}
			else	if(score>=75)
		 	{
			  			grade = 3.50;
			  			printf("You have got %f", grade);
			}
			  		else	if(score>=70)
			  		{
								grade=3.00;
								printf("You have got %f", grade);
			  		}
				   			else	if(score>=65)
				   			{
									grade=2.50;
									printf("You have got %f", grade);
				  			}
									else	if(score>=60)
									{
												grade=2.00;
												printf("You have got %f", grade);
									}
							 				else	if(score>=55)
							 				{
							 							grade=1.50;
							 							printf("You have got %f", grade);
							 				}
								  					else	if(score>=50)
								  					{
																grade=1.00;
																printf("You have got %f", grade);
								  					}
									   						else	if(score>=0&&score<50)
									   						{
																		grade=0.00;
																		printf("You have got %f", grade);
								       						}
										    						else
										    							printf("Your score must not be less than 0.00");						
}
																			
																			
																			
																			
																			
																			
																			
													
													
													
													
													
													
													
											
