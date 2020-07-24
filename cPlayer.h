#pragma once
#include"cObject.h"

class cTimer;
class cPlayer: public cObject
{
private:
	DWORD m_CurTime, m_OldTime;
	cTexture* m_image;
	Vec2 m_pos;
	cTimer* m_timer;

	BOOL m_bIsSkillOn;		// 스킬 실행 여부
	BOOL m_bIsSkillKeyOn;		// 스킬 키 입력 가능 여부
	cTimer* m_SkillTimer;		// 스킬 타이머 (스킬 지속시간)


public:
	cPlayer();
	virtual ~cPlayer();
	
	int speed = 0;
	int HP;
	// cObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Collision(cObject* obj) override;
};

