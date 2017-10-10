/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:43:55 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/10 17:57:51 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static int checkInt(std::string str)
{
	size_t i = 0;
	int value = 0;
	int neg = 1;

	if (str[0] == '-') {
		neg = -1;
		i++;
	}

	for (; i < str.size(); i++) {
		if (isdigit(str[i])) {
			value *= 10;
			value += (static_cast<int>(str[i]) - 48);
		} else if (str[i] == '.' || str[i] == 'f') {
			break;
		} else {
			throw std::bad_cast();
		}
	}

	return value * neg;
}

static char checkChar(std::string str)
{
	if (str.size() == 1) {
		if (isdigit(str[0])) {
			throw std::bad_exception();
		}
		return str[0];
	} else {
		if (int val = checkInt(str)) {
			if (val >= 32 && val <= 126) {
				return static_cast<char>(val);
			} else {
				throw std::bad_cast();
			}
		} else {
			throw std::bad_cast();
		}
	}
}

static double 		checkDouble(std::string str)
{
	size_t i = 0;
	double value = 0;
	double div = 1;
	bool isDecim = false;
	int neg = 1;

	if (str == "nan" || str == "-inf" || str == "+inf") {
		throw std::bad_exception();
	}

	if (str[0] == '-') {
		neg = -1;
		i++;
	}

	for (; i < str.size(); i++) {
		if (isdigit(str[i])) {
			if (isDecim) {
				div *= 10;
			}
			value *= 10;
			value += (static_cast<double>(str[i]) - 48);
		} else if (str[i] == '.') {
			isDecim = true;
		} else if (str[i] == 'f') {
			break;
		} else {
			throw std::bad_cast();
		}
	}

	return (value / div) * neg;
}

static float 	checkFloat(std::string str)
{
	double value = checkDouble(str);

	if (str == "nan" || str == "-inf" || str == "+inf") {
		throw std::bad_exception();
	}

	return static_cast<float>(value);
}

void 		convert(std::string str)
{
	std::cout << "char: ";
	try {
		std::cout << checkChar(str) << std::endl;
	} catch (std::bad_cast & e) {
		std::cout << "impossible" << std::endl;
	} catch (std::bad_exception & e) {
		std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	try {
		std::cout << checkInt(str) << std::endl;
	} catch (std::bad_cast & e) {
		std::cout << "impossible" << std::endl;
	}

	std::cout << "float: ";
	try {
		float f_value = checkFloat(str);
		std::cout << f_value << (f_value - static_cast<int>(f_value) == 0 ? ".0" : "") << "f" << std::endl;
	} catch (std::bad_cast & e) {
		std::cout << "impossible" << std::endl;
	} catch (std::bad_exception & e) {
		std::cout << str << "f" << std::endl;
	}

	std::cout << "double: ";
	try {
		double d_value = checkDouble(str);
		std::cout << d_value << (d_value - static_cast<int>(d_value) == 0 ? ".0" : "") << std::endl;
	} catch (std::bad_cast & e) {
		std::cout << "impossible" << std::endl;
	} catch (std::bad_exception & e) {
		std::cout << str << std::endl;
	}

	return ;
}

int main(int argc, char const *argv[])
{
	std::string str;

	if (argc == 2 && argv[1] && static_cast<std::string>(argv[1]) != "") {
		str = static_cast<std::string>(argv[1]);

		convert(argv[1]);
	} else {
		std::cout << "Error with paramter(s)" << std::endl;
	}

	return 0;
}
