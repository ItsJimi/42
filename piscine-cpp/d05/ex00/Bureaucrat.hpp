/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 11:29:02 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/09 13:56:56 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
public:
  Bureaucrat(std::string name, int grade);
  Bureaucrat(Bureaucrat const & src);
  ~Bureaucrat(void);

  Bureaucrat& operator=(Bureaucrat const & rhs);

  void GradeTooHighException(void);
  void GradeTooLowException(void);

  std::string const getName(void) const;
  int getGrade(void) const;

private:
  Bureaucrat(void);

  std::string _name;
  int _grade;
};

#endif