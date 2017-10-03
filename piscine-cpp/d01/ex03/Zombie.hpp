/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:44:44 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 11:25:13 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
  public:
    Zombie(void);
    ~Zombie(void);
    void init(std::string name, std::string type);
    void announce() const;

  private:
    std::string _name;
    std::string _type;
};

#endif