#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <map>
#include "Logger.h"

//INI文件结点存储结构
class IniNode
{
public:
    IniNode(std::string root, std::string key, std::string value)
    {
        this->root = root;
        this->key = key;
        this->value = value;
    }
    std::string root;
    std::string key;
    std::string value;
};

//键值对结构体
class SubNode
{
public:
    void InsertElement(std::string key, std::string value)
    {
        sub_node.insert(std::pair<std::string, std::string>(key, value));
    }
    std::map<std::string, std::string> sub_node;
};

//INI文件操作类
class CMyIni
{
private:
    /// <summary>
    ///     INI文件内容的存储变量
    /// </summary>
    std::map<std::string, SubNode> map_ini;
public:
    CMyIni();
    ~CMyIni();

public:
    /// <summary>
    ///     读取INI文件
    /// </summary>
    /// <param name="path"></param>
    /// <returns></returns>
    int ReadIni(std::string path);
    
    /// <summary>
    ///     由根结点和键获取值
    /// </summary>
    /// <param name="root"></param>
    /// <param name="key"></param>
    /// <returns></returns>
    std::string GetValue(std::string root, std::string key);
    
    /// <summary>
    ///     获取INI文件的结点数
    /// </summary>
    /// <returns></returns>
    std::vector<IniNode>::size_type GetSize();
    
    /// <summary>
    ///     设置根结点和键获取值
    /// </summary>
    /// <param name="root"></param>
    /// <param name="key"></param>
    /// <param name="value"></param>
    /// <returns></returns>
    std::vector<IniNode>::size_type SetValue(std::string root, std::string key, std::string value);
    
    /// <summary>
    ///     写入INI文件
    /// </summary>
    /// <param name="path"></param>
    /// <returns></returns>
    int WriteIni(std::string path);
    
    /// <summary>
    ///     清空
    /// </summary>
    void Clear();
    
    /// <summary>
    ///     遍历打印INI文件
    /// </summary>
    void Travel();
};
