#pragma once
#include <string>
#include <vector>

template <typename T>
__interface IRepository
{
public:
    std::vector<T> getAll() const;

    void add(const T& user);

    void Remove(const T& user);

    void update(const T& user);
};