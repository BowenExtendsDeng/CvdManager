#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <map>
#include "Logger.h"

//INI�ļ����洢�ṹ
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

//��ֵ�Խṹ��
class SubNode
{
public:
    void InsertElement(std::string key, std::string value)
    {
        sub_node.insert(std::pair<std::string, std::string>(key, value));
    }
    std::map<std::string, std::string> sub_node;
};

//INI�ļ�������
class CMyIni
{
private:
    /// <summary>
    ///     INI�ļ����ݵĴ洢����
    /// </summary>
    std::map<std::string, SubNode> map_ini;
public:
    CMyIni();
    ~CMyIni();

public:
    /// <summary>
    ///     ��ȡINI�ļ�
    /// </summary>
    /// <param name="path"></param>
    /// <returns></returns>
    int ReadIni(std::string path);
    
    /// <summary>
    ///     �ɸ����ͼ���ȡֵ
    /// </summary>
    /// <param name="root"></param>
    /// <param name="key"></param>
    /// <returns></returns>
    std::string GetValue(std::string root, std::string key);
    
    /// <summary>
    ///     ��ȡINI�ļ��Ľ����
    /// </summary>
    /// <returns></returns>
    std::vector<IniNode>::size_type GetSize();
    
    /// <summary>
    ///     ���ø����ͼ���ȡֵ
    /// </summary>
    /// <param name="root"></param>
    /// <param name="key"></param>
    /// <param name="value"></param>
    /// <returns></returns>
    std::vector<IniNode>::size_type SetValue(std::string root, std::string key, std::string value);
    
    /// <summary>
    ///     д��INI�ļ�
    /// </summary>
    /// <param name="path"></param>
    /// <returns></returns>
    int WriteIni(std::string path);
    
    /// <summary>
    ///     ���
    /// </summary>
    void Clear();
    
    /// <summary>
    ///     ������ӡINI�ļ�
    /// </summary>
    void Travel();
};
