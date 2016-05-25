#include "SwapConstruct.h"

String::String()
	: m_data(nullptr), m_len(0)
{}

String::~String()
{
	if (m_data) {
		delete m_data;
		m_data = nullptr;
	}
}

inline
void swap(String& lhs, String& rhs)
{
	using std::swap;
	swap(lhs.m_data, rhs.m_data);
	swap(lhs.m_len, rhs.m_len);
}

String::String(const String& rhs)
	:
{

}