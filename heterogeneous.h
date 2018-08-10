#pragma once

#include <tuple>

/*
NOTE: all types must be unique
*/
template<template<typename...> typename Container, typename... Ts>
struct heterogeneous
{
	std::tuple<Container<Ts>...> containers;

	template<typename T>
	auto& get()
	{
		return std::get<Container<T>>(containers);
	}
};

template<template<typename...> typename Container, typename Key, typename... Ts>
struct heterogeneous_map
{
	std::tuple<Container<Key, Ts>...> containers;

	template<typename T>
	auto& get()
	{
		return std::get<Container<Key, T>>(containers);
	}
};


//template<typename... Ts>
//struct heterogeneous
//{
//	std::tuple<std::vector<Ts>...> containers;
//
//	template<typename T>
//	auto& get()
//	{
//		return std::get<std::vector<T>>(containers);
//	}
//};