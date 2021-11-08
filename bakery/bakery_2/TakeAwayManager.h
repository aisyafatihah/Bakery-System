#ifndef TAKEAWAYMANAGER_H
#define TAKEAWAYMANAGER_H

class TakeAwayManager
{
public:
	int insertOrderTA(TakeAway* takeaway);
	int cancelOrderTA(TakeAway* takeaway);
	TakeAway* printOrderTA(string Cust_Name);
};
#endif 
