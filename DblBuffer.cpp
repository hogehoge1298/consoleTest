#include "DblBuffer.h"
#include <cstdlib>


DblBuffer::DblBuffer(int x, int y)
	:m_swapped(false),
	mSizeX(x),
	mSizeY(y)
{
	m_hCns1 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	m_hCns2 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	SetConsoleActiveScreenBuffer(m_hCns1);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(m_hCns1, &info);
	SetConsoleCursorInfo(m_hCns2, &info);
}


DblBuffer::~DblBuffer()
{
	CloseHandle(m_hCns1);
	CloseHandle(m_hCns2);
}

void DblBuffer::setColor(int col)
{
	WORD attr = 0;
	if (col & INTENSITY)
		attr |= FOREGROUND_INTENSITY;
	if (col & RED_MASK)
		attr |= FOREGROUND_RED;
	if (col & GREEN_MASK)
		attr |= FOREGROUND_GREEN;
	if (col & BLUE_MASK)
		attr |= FOREGROUND_BLUE;
	SetConsoleTextAttribute(m_swapped ? m_hCns1 : m_hCns2, attr);
}

void DblBuffer::setColor(int fg, int bg)
{
	WORD attr = 0;
	if (fg & INTENSITY)
		attr |= FOREGROUND_INTENSITY;
	if (fg & RED_MASK)
		attr |= FOREGROUND_RED;
	if (fg & GREEN_MASK)
		attr |= FOREGROUND_GREEN;
	if (fg & BLUE_MASK)
		attr |= FOREGROUND_BLUE;

	if (bg & INTENSITY)
		attr |= FOREGROUND_INTENSITY;
	if (bg & RED_MASK)
		attr |= FOREGROUND_RED;
	if (bg & GREEN_MASK)
		attr |= FOREGROUND_GREEN;
	if (bg & BLUE_MASK)
		attr |= FOREGROUND_BLUE;

	SetConsoleTextAttribute(m_swapped ? m_hCns1 : m_hCns2, attr);
}

void DblBuffer::setCursorPos(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(m_swapped ? m_hCns1 : m_hCns2, pos);
}

void DblBuffer::write(const char *ptr)
{
	DWORD len = strlen(ptr);
	WriteConsoleA(m_swapped ? m_hCns1 : m_hCns2, ptr, len, &len, 0);
}

void DblBuffer::write(const wchar_t *ptr)
{
	DWORD len = wcslen(ptr);
	WriteConsoleA(m_swapped ? m_hCns1 : m_hCns2, ptr, len, &len, 0);
}

void DblBuffer::write(const std::string &str)
{
	DWORD len = str.size();
	WriteConsoleA(m_swapped ? m_hCns1 : m_hCns2, str.c_str(), len, &len, 0);
}

void DblBuffer::write(const std::wstring &str)
{
	DWORD len = str.size();
	WriteConsoleA(m_swapped ? m_hCns1 : m_hCns2, str.c_str(), len, &len, 0);
}

void DblBuffer::clear(int fg, int bg)
{
	for (int y = 0; y < mSizeY; y++) {
		for (int x = 0; x < mSizeX; x++) {
			setColor(fg, bg);
		}
	}
}

void DblBuffer::swap()
{
	//std::system("cls");
	if ((m_swapped = !m_swapped))
	{
		
		SetConsoleActiveScreenBuffer(m_hCns2);
	}
	else {
		SetConsoleActiveScreenBuffer(m_hCns1);
	}
}
