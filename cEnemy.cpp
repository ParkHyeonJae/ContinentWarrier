#include "DXUT.h"
#include "cEnemy.h"
#include "cTimer.h"
#include "cPlayer.h"
#include "cEnemyBullet.h"

cEnemy::cEnemy(Vec2 pos):m_pos(pos)
{
	SetTag("Enemy");
	m_image = IMAGE->FindImage("Enemy");
	m_timer = new cTimer(3);
	SetCollTag("OBB");
	SetPos(m_pos);
	HP = 3;
}

cEnemy::~cEnemy()
{
}

void cEnemy::Update()
{
	SetPos(m_pos);

	a += 0.01;
	//rot = atan2(OBJ->m_player->GetPos().y - m_pos.y, OBJ->m_player->GetPos().x - m_pos.x);
	//SetRot(D3DXToDegree(rot + 1.5));
	//D3DXVec2Normalize(&pos, &Vec2(m_pos - OBJ->m_player->GetPos()));
	m_pos.y -= 20.0f * DXUTGetElapsedTime();
	SetRect(m_pos, m_image);
	OBJ->AddObj(new cEnemyBullet(Vec2(m_pos)));

}

void cEnemy::Render()
{
	RENDER->Render(m_image, m_pos, Vec2(1, 1), rot + 1.5, 0.f);

}

void cEnemy::UIRender()
{
}

void cEnemy::Collision(cObject* obj)
{
	if (obj->GetTag() == "Player")
	{
		ObjDie();
	}

}