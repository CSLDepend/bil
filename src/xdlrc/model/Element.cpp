/**
* \file Element.cpp
* \brief Contains definition of Element class.
*/

#include <xdlrc/model/Element.hpp>

using namespace bil;


Element::Element():
  m_name(),
  m_pins(),
  m_conns(),
  m_options()
{

}


std::string& Element::name()
{
    return m_name;
}


const std::string& Element::name() const
{
    return m_name;
}

Pins& Element::pins()
{
    return m_pins;
}


const Pins& Element::pins() const
{
    return m_pins;
}


ElementConns& Element::conns()
{
    return m_conns;
}

const ElementConns& Element::conns() const
{
    return m_conns;
}

ConfigurationOptions& Element::options()
{
    return m_options;
}


const ConfigurationOptions& Element::options() const
{
    return m_options;
}


void Element::clear()
{
    m_name.clear();
    m_options.clear();
}
