#include <stdio.h>
#include <stdlib.h>

int main(){
	float Ja, Ma, JDM, MDM;
	int Jm, Mm;
	printf("Please enter the John's deposit amount and deposit month\n");
	scanf("%f %d", &Ja, &Jm);
	printf("\nPlease enter the Mary's deposit amount and deposit month\n");
	scanf("%f %d", &Ma, &Mm);
	printf("\nJohn's deposit amount is %.0f, and deposit month is %d", Ja, Jm);
	printf("\nMary's deposit amount is %.0f, and deposit month is %d", Ma, Mm);
	if(Ja <= 100000){
		if(Jm == 1){
			JDM = Ja * 0.005;
		}
		else{
			if(Jm == 2){
				JDM = Ja * 0.005;
			}
			else{
				if(Jm == 3){
					JDM = Ja * 0.005;
				}
				else{
					if(Jm == 4){
						JDM = Ja * 0.01;
					}
					else{
						if(Jm == 5){
							JDM = Ja * 0.01;
						}
						else{
							if(Jm == 6){
								JDM = Ja * 0.01;
							}
							else{
								JDM = Ja * 0.015;
							}
						}
					}
				}
			}
		}
	}
	else{
		if(100000 < Ja && Ja <= 1000000){
			if(Jm == 1){
				JDM = Ja * 0.007;
			}
			else{
				if(Jm == 2){
					JDM = Ja * 0.007;
				}
				else{
					if(Jm == 3){
						JDM = Ja * 0.007;
					}
					else{
						if(Jm == 4){
							JDM = Ja * 0.012;
						}
						else{
							if(Jm == 5){
								JDM = Ja * 0.012;
							}
							else{
								if(Jm == 6){
									JDM = Ja * 0.012;
								}
								else{
									JDM = Ja * 0.017;
								}
							}
						}
					}
				}
			}
		}
		else{
			if(1000000 < Ja && Ja <= 5000000){
				if(Jm == 1){
					JDM = Ja * 0.007;
				}
				else{
					if(Jm == 2){
						JDM = Ja * 0.007;
					}
					else{
						if(Jm == 3){
							JDM = Ja * 0.007;
						}
						else{
							if(Jm == 4){
								JDM = Ja * 0.012;
							}
							else{
								if(Jm == 5){
									JDM = Ja * 0.012;
								}
								else{
									if(Jm == 6){
										JDM = Ja * 0.012;
									}
									else{
										JDM = Ja * 0.017;
									}
								}
							}
						}
					}
				}
			}
			else{
				JDM = Ja * 0.005;
			}
		}
	}
	if(Ma <= 100000){
		if(Mm == 1){
			MDM = Ma * 0.005;
		}
		else{
			if(Mm == 2){
				MDM = Ma * 0.005;
			}
			else{
				if(Mm == 3){
					MDM = Ma * 0.005;
				}
				else{
					if(Mm == 4){
						MDM = Ma * 0.01;
					}
					else{
						if(Mm == 5){
							MDM = Ma * 0.01;
						}
						else{
							if(Mm == 6){
								MDM = Ma * 0.01;
							}
							else{
								MDM = Ma * 0.015;
							}
						}
					}
				}
			}
		}
	}
	else{
		if(100000 < Ma && Ma <= 1000000){
			if(Mm == 1){
				MDM = Ma * 0.007;
			}
			else{
				if(Mm == 2){
					MDM = Ma * 0.007;
				}
				else{
					if(Mm == 3){
						MDM = Ma * 0.007;
					}
					else{
						if(Mm == 4){
							MDM = Ma * 0.012;
						}
						else{
							if(Mm == 5){
								MDM = Ma * 0.012;
							}
							else{
								if(Mm == 6){
									MDM = Ma * 0.012;
								}
								else{
									MDM = Ma * 0.017;
								}
							}
						}
					}
				}
			}
		}
		else{
			if(1000000 < Ma && Ma <= 5000000){
				if(Mm == 1){
					MDM = Ma * 0.007;
				}
				else{
					if(Mm == 2){
						MDM = Ma * 0.007;
					}
					else{
						if(Mm == 3){
							MDM = Ma * 0.007;
						}
						else{
							if(Mm == 4){
								MDM = Ma * 0.012;
							}
							else{
								if(Mm == 5){
									MDM = Ma * 0.012;
								}
								else{
									if(Mm == 6){
										MDM = Ma * 0.012;
									}
									else{
										MDM = Ma * 0.017;
									}
								}
							}
						}
					}
				}
			}
			else{
				MDM = Ma * 0.005;
			}
		}
	}
	printf("\n\nJohnDM is %f", JDM);
	printf("\nMaryDM is %f", MDM);
	if(JDM > MDM){
		printf("\n\nJohn's deposit interest is best!\n");
	}
	else{
		printf("\n\nMary's deposit interest is best!\n");
	}
	return 0;
}
