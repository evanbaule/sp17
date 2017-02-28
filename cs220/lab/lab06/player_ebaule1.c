rps player_ebaule1(int round,rps *myhist,rps *opphist) {
	
	if(round <= 2){
		char i = rand()%3;
		switch(i) {
			case 0: return Rock;
			case 1: return Scissors;
		}
		return Paper;
	}
				
	rps last = myhist[round-1];
	if(last == Rock){
		char s = rand() % 100;
		if(s < 45){
			return Scissors;
		}
		if(s > 46 && s < 90){
			return Paper;		
		}
		return Rock;
	}

	if(last == Scissors){
		char s = rand() % 100;
		if(s < 45){
			return Paper;
		}
		if(s > 46 && s < 90){
			return Rock;		
		}
		return Scissors;
	}
	
	if(last == Paper){
		char s = rand() % 100;
		if(s < 45){
			return Rock;
		}
		if(s > 46 && s < 90){
			return Scissors;		
		}
		return Paper;
	}		
}

register_player(player_ebaule1,"ebaule1");
