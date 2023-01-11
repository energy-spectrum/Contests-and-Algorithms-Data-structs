#include <iostream>

#include <vector>
#include <deque>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>
#include <cmath>

#include <string>

using namespace std;


struct Folder {
public:
	string name;
	map<string, Folder*> folders;
	map<string, int> files;

	bool isBlack = false;

	Folder(){}

	Folder(string name) {
		this->name = name;
	}
};

class MainDir {
public:
	Folder *folder;

	MainDir(string name) {
		folder = new Folder(name);
	}

	Folder* addFolder(deque<string> dir, bool isBlack) {
		Folder *currentFolder = folder;

		while (dir.empty() == false) {
			string nameNextFolder = dir.front();
			dir.pop_front();

			if (currentFolder->folders.find(nameNextFolder) == currentFolder->folders.end()) {
				Folder *newFolder = new Folder(nameNextFolder);
				currentFolder->folders.insert({ nameNextFolder, newFolder });
			}

			bool isCurrentFolderBlack = currentFolder->isBlack;

			currentFolder = currentFolder->folders[nameNextFolder];

			currentFolder->isBlack = isCurrentFolderBlack || currentFolder->isBlack;
		}

		currentFolder->isBlack = isBlack || currentFolder->isBlack;
		return currentFolder;
	}

	void addFile(deque<string> dir, string ext) {
		Folder* currentFolder = addFolder(dir, false);
		currentFolder->files[ext] += 1;
	}

	void dfs(Folder &currentFolder, map<string, int> &files) {
		if (currentFolder.isBlack) {

			for (auto pair : currentFolder.files) {
				files[pair.first] += pair.second;
			}
		}

		for (auto pair : currentFolder.folders) {
			dfs(*pair.second, files);
		}
	}

	void getInfo(deque<string> dir) {
		Folder* currentFolder = folder;

		while (dir.empty() == false) {
			string nameNextFolder = dir.front();
			dir.pop_front();

			if (currentFolder->folders.find(nameNextFolder) == currentFolder->folders.end()) {
				cout << 0 << '\n';
				return;
			}

			currentFolder = currentFolder->folders[nameNextFolder];
		}

		map<string, int> files;
		dfs(*currentFolder, files);
		
		cout << files.size() << '\n';
		for (auto pair : files) {
			cout << "." << pair.first << ": " << pair.second << '\n';
		}
	}
};

void split(string& s, char sep, deque<string>& out)
{
	int start;
	int finish = 0;

	while ((start = s.find_first_not_of(sep, finish)) != string::npos)
	{
		finish = s.find(sep, start);
		out.push_back(s.substr(start, finish - start));
	}
}

int main()
{
	MainDir mainDir("/");

	int n; 
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string sDir;
		cin >> sDir;

		deque<string> dir;
		split(sDir, '/', dir);

		mainDir.addFolder(dir, true);
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		string sDir;
		cin >> sDir;

		deque<string> dir;
		split(sDir, '/', dir);

		string file = dir.back();
		dir.pop_back();

		deque<string> fileAndExt;
		split(file, '.', fileAndExt);

		mainDir.addFile(dir, fileAndExt.back());
	}

	int q;
	cin >> q;

	vector <deque<string>> req(q);

	for (int i = 0; i < q; i++) {
		string sDir;
		cin >> sDir;

		deque<string> dir;
		split(sDir, '/', dir);

		req[i] = dir;
	}

	for (int i = 0; i < q; i++) {
		mainDir.getInfo(req[i]);
	}

	return 0;
}
