/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:35:06 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/11 17:35:58 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

#include <iostream>
#include "Base.hpp"

class A : public Base {
public:
  A(void);
  A(A const & src);
  virtual ~A(void);

  A& operator=(A const & rhs);
};

#endif