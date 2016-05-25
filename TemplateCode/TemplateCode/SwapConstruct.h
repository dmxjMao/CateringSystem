#pragma once

/*�������һ����Ϊ��ָ����࣬�Ǿ�Ҫ����shared_ptr<char> m_data;*/
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
	String& operator=(String); //�����ƶ���ֵ��Ҳ�ǿ�����ֵ
	~String();
};


