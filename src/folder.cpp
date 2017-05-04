#include "folder.h"

#include <iostream>
#include <string>

using namespace std;


void Folder::add_folder(string path, string name)
{
    get_folder(path, 0)->m_folderTree.insert(new Folder(name, 0));
}


Folder* Folder::get_folder(string path, size_t depth)
{
    if (path_length(path) == depth)
        return this;
    if (path == "")
    {
        cout << "No path, inserting here" << endl;
        return this;
    }
    else
    {
        string front = path_pop(path);
        if (front == getName())
        {
            cout << "Myself, inserting to self: " << path << endl;
            front = path_pop(path);
            return get_folder(path, 0);
        }
        else
        {
            cout << "Looking for folder: " << path << endl;
            return m_folderTree.find(new Folder(front, 0));
        }
    }
}


void Folder::delete_folder(string path, string name)
{
    Folder *temp = get_folder(path, 1);
    string front = path_pop(path);
    temp->m_folderTree.erase(new Folder(front, 0));
}


std::ostream& operator<<(std::ostream &out, const Folder &folder)
{
    return out << folder.getName();
}

