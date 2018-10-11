#pragma once
class BaseGameEntity
{
private:
	//实体唯一识别ID
	int m_ID;

	//下一个有效ID， 每次创建新对象时更新
	static int m_iNextValidID;

	//构造函数中调用此函数确认ID被正确设置
	//在设置ID和增量前，确认值大于等于下一个有效ID
	void SetID(int val);
public:
	BaseGameEntity(int id);
	virtual ~BaseGameEntity();

	//游戏循环调用更新函数
	virtual void Update() = 0;
	int ID() const;
};

