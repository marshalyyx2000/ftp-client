/*
 * MIT License
 *
 * Copyright (c) 2019 Denis Kovalchuk
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef FTP_DATA_CONNECTION_HPP
#define FTP_DATA_CONNECTION_HPP

#include <fstream>
#include <boost/asio/ip/tcp.hpp>

namespace ftp::detail
{

class data_connection
{
public:
    data_connection();

    data_connection(const data_connection &) = delete;

    data_connection & operator=(const data_connection &) = delete;

    void open(const std::string & ip, uint16_t port);

    bool is_open() const;

    void close();

    std::string recv();

    void send_file(std::ifstream & file);

    void recv_file(std::ofstream & file);

private:
    boost::asio::io_context io_context_;
    boost::asio::ip::tcp::socket socket_;
    std::array<char, 4096> buffer_;
};

} // namespace ftp::detail
#endif //FTP_DATA_CONNECTION_HPP
