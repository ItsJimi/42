/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 10:32:20 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/02 18:28:59 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>

class Contact {
public:
  Contact();
  ~Contact();
  void add(void);
  void display(void);
  void displayAll(void);

private:
  std::string _firstname;
  std::string _lastname;
  std::string _nickname;
  std::string _login;
  std::string _postalAddress;
  std::string _emailAddress;
  std::string _phoneNumber;
  std::string _birthdayDate;
  std::string _favoriteMeal;
  std::string _underwearColor;
  std::string _darkestSecret;

  void _print(std::string str);
};

#endif