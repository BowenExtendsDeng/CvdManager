#include "CMyIni.h"

#define INIDEBUG

CMyIni::CMyIni()
{
}


CMyIni::~CMyIni()
{
}

std::string& TrimString(std::string& str)
{
    std::string::size_type pos = 0;
    while (str.npos != (pos = str.find(" ")))
        str = str.replace(pos, pos + 1, "");
    return str;
}

int CMyIni::ReadIni(std::string path)
{
    std::ifstream in_conf_file(path.c_str());
    if (!in_conf_file) return 0;
    std::string str_line = "";
    std::string str_root = "";
    std::vector<IniNode> vec_ini;
    while (getline(in_conf_file, str_line))
    {
        std::string::size_type left_pos = 0;
        std::string::size_type right_pos = 0;
        std::string::size_type equal_div_pos = 0;
        std::string str_key = "";
        std::string str_value = "";
        if ((str_line.npos != (left_pos = str_line.find("["))) && (str_line.npos != (right_pos = str_line.find("]"))))
        {
            //cout << str_line.substr(left_pos+1, right_pos-1) << endl;
            str_root = str_line.substr(left_pos + 1, right_pos - 1);
        }

        if (str_line.npos != (equal_div_pos = str_line.find("=")))
        {
            str_key = str_line.substr(0, equal_div_pos);
            str_value = str_line.substr(equal_div_pos + 1, str_line.size() - 1);
            str_key = TrimString(str_key);
            str_value = TrimString(str_value);
            //cout << str_key << "=" << str_value << endl;
        }

        if ((!str_root.empty()) && (!str_key.empty()) && (!str_value.empty()))
        {
            IniNode ini_node(str_root, str_key, str_value);
            vec_ini.push_back(ini_node);
            //cout << vec_ini.size() << endl;
        }
    }
    in_conf_file.close();
    in_conf_file.clear();

    //vector convert to map
    std::map<std::string, std::string> map_tmp;
    for (std::vector<IniNode>::iterator itr = vec_ini.begin(); itr != vec_ini.end(); ++itr)
    {
        map_tmp.insert(std::pair<std::string, std::string>(itr->root, ""));
    } //提取出根节点
    for (std::map<std::string, std::string>::iterator itr = map_tmp.begin(); itr != map_tmp.end(); ++itr)
    {
#ifdef INIDEBUG
        std::cout << "根节点： " << itr->first << std::endl;
#endif  //INIDEBUG
        SubNode sn;
        for (std::vector<IniNode>::iterator sub_itr = vec_ini.begin(); sub_itr != vec_ini.end(); ++sub_itr)
        {
            if (sub_itr->root == itr->first)
            {
#ifdef INIDEBUG
                std::cout << "键值对： " << sub_itr->key << "=" << sub_itr->value << std::endl;
#endif  //INIDEBUG
                sn.InsertElement(sub_itr->key, sub_itr->value);
            }
        }
        map_ini.insert(std::pair<std::string, SubNode>(itr->first, sn));
    }
    return 1;
}

std::string CMyIni::GetValue(std::string root, std::string key)
{
    std::map<std::string, SubNode>::iterator itr = map_ini.find(root);
    std::map<std::string, std::string>::iterator sub_itr = itr->second.sub_node.find(key);
    if (!(sub_itr->second).empty())
        return sub_itr->second;
    return "";
}

int CMyIni::WriteIni(std::string path)
{
    std::ofstream out_conf_file(path.c_str());
    if (!out_conf_file)
        return -1;
    //cout << map_ini.size() << endl;
    for (std::map<std::string, SubNode>::iterator itr = map_ini.begin(); itr != map_ini.end(); ++itr)
    {
        //cout << itr->first << endl;
        out_conf_file << "[" << itr->first << "]" << std::endl;
        for (std::map<std::string, std::string>::iterator sub_itr = itr->second.sub_node.begin(); sub_itr != itr->second.sub_node.end(); ++sub_itr)
        {
            //cout << sub_itr->first << "=" << sub_itr->second << endl;
            out_conf_file << sub_itr->first << "=" << sub_itr->second << std::endl;
        }
    }

    out_conf_file.close();
    out_conf_file.clear();

    return 1;
}

std::vector<IniNode>::size_type CMyIni::SetValue(std::string root, std::string key, std::string value)
{
    std::map<std::string, SubNode>::iterator itr = map_ini.find(root);  //查找
    if (map_ini.end() != itr)
    {
        //itr->second.sub_node.insert(pair<string, string>(key, value));
        itr->second.sub_node[key] = value;
    } //根节点已经存在了，更新值
    else
    {
        SubNode sn;
        sn.InsertElement(key, value);
        map_ini.insert(std::pair<std::string, SubNode>(root, sn));
    } //根节点不存在，添加值

    return map_ini.size();
}

void CMyIni::Travel()
{
    Logger::Log("-----------------------------------", Logger::INFO);
    for (std::map<std::string, SubNode>::iterator itr = this->map_ini.begin(); itr != this->map_ini.end(); ++itr)
    {
        //root
        
        Logger::Log("start to read config.ini", Logger::INFO);
        std::string header ="[" + itr->first + "]";
        Logger::Log(header, Logger::INFO);
        for (std::map<std::string, std::string>::iterator itr1 = itr->second.sub_node.begin(); itr1 != itr->second.sub_node.end();
            ++itr1)
        {
            std::string line =itr1->first + " = " + itr1->second;
            Logger::Log(line, Logger::INFO);
        }
    }
    Logger::Log("-----------------------------------", Logger::INFO);
}

std::vector<IniNode>::size_type CMyIni::GetSize()
{ 
    return map_ini.size(); 
}

void CMyIni::Clear()
{ 
    map_ini.clear(); 
}