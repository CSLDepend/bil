/**
* \file Element.hpp
* \brief Contains declaration of Element class.
*/

#pragma once
#ifndef BIL_ELEMENT_HPP
#define BIL_ELEMENT_HPP

#include <string>
#include <vector>
#include <serialization/ElementBS.hpp>
#include <xdlrc/model/Pin.hpp>

namespace bil {

    /// An ordered list of configuration options.
    typedef std::vector<std::string> ConfigurationOptions;

    /**
     * \brief ElementConn represents connects between elements within
     * a primtive_def
     */
    class ElementConn {
    public:

        ElementConn() { }

        std::string& pin() { return m_pin; }
        const std::string& pin() const { return m_pin; }

        std::string& dstElement() { return m_dstElement; }
        const std::string& dstElement() const { return m_dstElement; }

        std::string& dstPin() { return m_dstPin; }
        const std::string& dstPin() const { return m_dstPin; }

    private:
        std::string m_pin;
        std::string m_dstElement;
        std::string m_dstPin;
    };

    typedef std::vector<ElementConn> ElementConns;

    /**
    * \brief An element of a primitive.
    *
    * Elements are configurable subunits of primitives. Each element has got an
    * unique name inside its primitive and a list of configuration options. Each
    * single option denotes a distinct configuration of the whole element.
    */
    class Element {
    public:

        /**********************************************************************/
        /* CONSTRUCTION / DESTRUCTION                                         */
        /**********************************************************************/

        /**
        * \brief Constructs a new Element instance.
        */
        Element();


        /**********************************************************************/
        /* ELEMENT NAME                                                       */
        /**********************************************************************/

        /**
        * \brief Gets element name.
        * \return The name.
        */
        std::string& name();

        /**
        * \brief Gets element name read only.
        * \return The name.
        */
        const std::string& name() const;


        /**********************************************************************/
        /* PINS                                                               */
        /**********************************************************************/

        /**
        * \brief Gets pins.
        * \return The pins.
        */
        Pins& pins();

        /**
        * \brief Gets pins read only.
        * \return The pins.
        */
        const Pins& pins() const;

        /**********************************************************************
         * Connections
         **********************************************************************/

        /**
        * \brief Gets connections.
        * \return The connections.
        */
        ElementConns& conns();

        /**
        * \brief Gets conns read only.
        * \return The conns.
        */
        const ElementConns& conns() const;

        /**********************************************************************/
        /* CONFIGURATION OPTIONS                                              */
        /**********************************************************************/

        /**
        * \brief Gets configuration options.
        * \return The configuration options.
        */
        ConfigurationOptions& options();

        /**
        * \brief Gets configuration options read only.
        * \return The configuration options.
        */
        const ConfigurationOptions& options() const;


        /**********************************************************************/
        /* MODIFICATORS                                                       */
        /**********************************************************************/

        /**
        * \brief Resets all properties to default values.
        */
        void clear();


    private:

        friend void writeBinary(const Element& data, std::ostream& outputStream);
        friend void readBinary(Element& data, std::istream& inputStream);

        std::string m_name;
        Pins m_pins;
        ElementConns m_conns;
        ConfigurationOptions m_options;

    };

    /// An ordered list of elements.
    typedef std::vector<Element> Elements;

}

#endif
