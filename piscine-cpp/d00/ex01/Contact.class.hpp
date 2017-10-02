/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 10:32:20 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/02 15:05:27 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact {
public:
  Contact();
  ~Contact();
  void add(void);
  void display(void);
  void displayAll(void);

  std::string firstname;
  std::string lastname;
  std::string nickname;
  std::string login;
  std::string postalAddress;
  std::string emailAddress;
  std::string phoneNumber;
  std::string birthdayDate;
  std::string favoriteMeal;
  std::string underwearColor;
  std::string darkestSecret;

private:
  void _print(std::string str);
};