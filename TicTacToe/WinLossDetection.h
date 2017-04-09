#pragma once

bool noWin(int displayGrid[3][3]);
bool diagonalDetection(int displayGrid[3][3], int OorX);
bool verticalDetection(int displayGrid[3][3], int OorX);
bool horazontalDetection(int displayGrid[3][3], int OorX);

int gameOver(int displayGrid[3][3])
{
	//Detect for X win
	if (diagonalDetection(displayGrid, 1) || verticalDetection(displayGrid, 1) || horazontalDetection(displayGrid, 1))
		return 1;
	if (diagonalDetection(displayGrid, 2) || verticalDetection(displayGrid, 2) || horazontalDetection(displayGrid, 2))
		return 2;
	if (noWin(displayGrid))
		return 3;
	return 0;
}

bool noWin(int displayGrid[3][3])
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (displayGrid[x][y] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool diagonalDetection(int displayGrid[3][3], int OorX)
{
	if (displayGrid[0][0] == OorX && displayGrid[1][1] == OorX && displayGrid[2][2] == OorX)
	{
		return true;
	}
	if (displayGrid[2][0] == OorX && displayGrid[1][1] == OorX && displayGrid[0][2] == OorX)
	{
		return true;
	}
	return false;
}

bool verticalDetection(int displayGrid[3][3], int OorX)
{
	for (int x = 0; x < 3; x++)
	{
		if (displayGrid[x][0] == OorX && displayGrid[x][1] == OorX && displayGrid[x][2] == OorX)
		{
			return true;
		}
	}
	return false;
}

bool horazontalDetection(int displayGrid[3][3], int OorX)
{
	for (int y = 0; y < 3; y++)
	{
		if (displayGrid[0][y] == OorX && displayGrid[1][y] == OorX && displayGrid[2][y] == OorX)
		{
			return true;
		}
	}
	return false;
}