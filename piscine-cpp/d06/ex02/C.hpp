/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:36:48 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/11 17:37:31 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

#include <iostream>
#include "Base.hpp"

class C : public Base {
public:
  C(void);
  C(C const & src);
  virtual ~C(void);

  C& operator=(C const & rhs);
};

#endif