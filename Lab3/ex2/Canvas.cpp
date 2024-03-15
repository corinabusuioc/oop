#include "Canvas.h"
#include <stdio.h>
Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->m = new char*[width];
	for (int i = 0;i < width;i++)
		this->m[i] = new char[height];
	for (int i = 0;i < width;i++)
	{
		m[i][height] = '\0';
		for (int j = 0;j < height;j++)
			this->m[i][j] = ' ';
	}
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0;i < this->width;i++)
		for (int j = 0;j < this->height;j++)
			if (((i - x) * (i - x) + (j - y) * (j - y)) >= ray * (ray-1) && ((i - x) * (i - x) + (j - y) * (j - y)) <= ray * (ray+1))
				SetPoint(i, j, ch);
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0;i < this->width;i++)
		for (int j = 0;j < this->height;j++)
			if (((i - x) * (i - x) + (j - y) * (j - y)) <= ray * ray)
				SetPoint(i, j, ch);
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left;i <= right;i++)
	{
		SetPoint(i, top, ch);
		SetPoint(i, bottom, ch);
	}
	for (int i = top;i <= bottom;i++)
	{
		SetPoint(left, i, ch);
		SetPoint(right, i, ch);
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left;i <= right;i++)
		for (int j = top;j <= bottom;j++)
			SetPoint(i, j, ch);
}
void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x < this->width && y >= 0 && y < this->height)
		m[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int D = 2 * dy - dx;
	int y = y1;
	for (int x = x1; x <= x2; x++)
	{
		SetPoint(x, y, ch);
		if (D > 0)
		{
			y++;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
	}
}
void Canvas::Print()
{
	for (int i = 0;i < this->width;i++)
		printf("%s\n", this->m[i]);
}
void Canvas::Clear()
{
	for (int i = 0;i < this->width;i++)
		for (int j = 0;j < this->height;j++)
			this->m[i][j] = ' ';
	this->width = 0;
	this->height = 0;
}