#pragma once

/*如果定义一个行为像指针的类，那就要定义shared_ptr<char> m_data;*/
inline void swap(String&, String&);

class String
{
	friend void swap(String&, String&);
private:
	char*		m_data;
	int			m_len;

public:
	String();
	String(const String&);
	String(String&&);
	String(const char*);
	String& operator=(const char*);
	String& operator=(String); //既是移动赋值，也是拷贝赋值
	~String();
};


