/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:27:20 by amoinier          #+#    #+#             */
/*   Updated: 2017/10/10 17:48:11 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <iostream>
#include <sstream>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void * serialize( void )
{
	std::string str;
	std::stringstream stream;
	int value;
	const char list[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < 8; i++) {
		str.push_back(list[rand() % 62]);
	}

	value = rand() % 2147483647;
	stream << value;
	str += stream.str();

	for (int i = 0; i < 8; i++) {
		str.push_back(list[rand() % 62]);
	}

	return reinterpret_cast<void *>(const_cast<char *>(str.c_str()));
}

Data * deserialize( void * raw )
{
	Data *data = new Data();
	std::string str;

	str = static_cast<std::string>(reinterpret_cast<char *>(raw));
	data->s1 = str.substr(0, 8);
	data->s2 = str.substr(str.size() - 8, 8);
	data->n = std::atoi(str.substr(8, str.size() - 16).c_str());

	return data;
}

int main(void)
{
	std::srand(std::time(NULL) + std::clock());
	void* addr = serialize();
	Data* data = deserialize(addr);

	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;

	delete data;

	return 0;
}
