/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DataManager.hpp
*/

#include "DataManager.hpp"

template <typename T>
Datadictionnary<T>::Datadictionnary()
{
    data = nullptr;
    type = nullptr;
    next = nullptr;
}

template <typename T>
Datadictionnary<T>::Datadictionnary(T data, DataType type)
{
    this->data = data;
    this->type = type;
    next = nullptr;
}

template <typename T>
Datadictionnary<T>::~Datadictionnary()
{
}

template <typename T>
DataManager<T>::DataManager()
{
    _data = nullptr;
}

template <typename T>
DataManager<T>::~DataManager()
{
    Datadictionnary<T> *tmp = _data;
    while (tmp) {
        Datadictionnary<T> *next = tmp->next;
        delete tmp;
        tmp = next;
    }
}

template <typename T>
void DataManager<T>::addData(DataType type, T data)
{
    Datadictionnary<T> *newData = new Datadictionnary<T>(data, type);
    Datadictionnary<T> *tmp = _data;
    while (tmp && tmp->next) {
        tmp = tmp->next;
    }
    if (tmp)
        tmp->next = newData;
    else
        _data = newData;
}

template <typename T>
void DataManager<T>::removeData(DataType type)
{
    Datadictionnary<T> *tmp = _data;
    Datadictionnary<T> *prev = nullptr;
    while (tmp && tmp->type != type) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (!tmp)
        return;
    if (prev)
        prev->next = tmp->next;
    else
        _data = tmp->next;
    delete tmp;
}

template <typename T>
void DataManager<T>::setData(DataType type, T data)
{
    Datadictionnary<T> *tmp = _data;
    while (tmp && tmp->type != type) {
        tmp = tmp->next;
    }
    if (!tmp)
        addData(type, data);
    tmp->data = data;
}

template <typename T>
T DataManager<T>::getData(DataType type)
{
    Datadictionnary<T> *tmp = _data;
    while (tmp && tmp->type != type) {
        tmp = tmp->next;
    }
    if (!tmp)
        return nullptr;
    return tmp->data;
}
