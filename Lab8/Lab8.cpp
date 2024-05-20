#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<queue>
std::ifstream fin("int.txt");

struct compare {
	bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const 
	{
		if (a.second != b.second) {
			return a.second < b.second;  
		}
		return a.first > b.first;  
	}
};

int main()
{
	std::string phrase, sep(" ,?!.");
	std::getline(fin, phrase);
	int n = 0;
	for (int i = 0;i < phrase.size();i++)
		if (sep.find(phrase[i]) != std::string::npos)
			n++;
	std::vector<std::string> words(n);
	n = 0;
	int begin = -2;
	for (int i = 0;i < phrase.size();i++)
	{
		if (sep.find(phrase[i]) != std::string::npos)
		{
			if (begin != -2 && begin != -1)
			{
				words[n] = phrase.substr(begin, i-begin);
				n++;
				begin = -1;
			}
		}
		else
			if (begin == -1 || begin == -2)
				begin = i;
	}
	std::map<std::string, int> frequence;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < words[i].size();j++)
			if (words[i][j] >= 'A' && words[i][j] <= 'Z')
				words[i][j] += 32;
		frequence[words[i]]++;
	}
	for (int i = 0;i < n - 1;i++)
		for (int j = i + 1;j < n;j++)
		{
			if (words[i] == words[j])
			{
				for (int k = j;k < n - 1;k++)
					words[k] = words[k + 1];
				n--;
				j--;
			}
		}
	std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, compare> q;
	for (const auto& item : frequence)
		q.push(item);
	while (!q.empty()) {
		const auto& item = q.top();
		std::cout << item.first << " => " << item.second << std::endl;
		q.pop();
	}
}