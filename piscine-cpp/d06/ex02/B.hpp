/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:36:22 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/11 17:37:46 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

#include <iostream>
#include "Base.hpp"

class B : public Base {
public:
  B(void);
  B(B const & src);
  virtual ~B(void);

  B& operator=(B const & rhs);
};

#endif