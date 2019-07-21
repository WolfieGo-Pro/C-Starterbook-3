#ifndef CHAR_BLUEPRINT_H
#define CHAR_BLUEPRINT_H

class Character_Blueprint
{
private:
	bool ghost;


public:
	Character_Blueprint();
	~Character_Blueprint();

	void punch();
	void jump();
	void fly();
	void shoot();
	void stance();
};

#endif // !1

