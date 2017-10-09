/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 11:30:12 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/09 14:00:55 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* CONSTRUCTORS */

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  if (grade < 1 || grade > 150) {
    throw std::exception();
  }
  this->_grade = grade;

  try {
  /* do some stuff with bureaucrats */
  } catch (std::exception & e) {
  /* handle exception */
  }

  return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
  *this = src;
  return;
}

Bureaucrat::~Bureaucrat(void) {
  return;
}

/* MEMBERS */

std::string const Bureaucrat::getName(void) const {
  return this->_name;
}

int Bureaucrat::getGrade(void) const {
  return this->_grade;
}

/* OPERATORS */

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & rhs) {
  this->_name = rhs.getName();
  this->_grade = rhs.getGrade();
  return *this;
}