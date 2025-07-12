-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 08, 2023 at 03:25 AM
-- Server version: 10.4.27-MariaDB
-- PHP Version: 8.2.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `rentals`
--

-- --------------------------------------------------------

--
-- Table structure for table `cars`
--

CREATE TABLE `cars` (
  `VehicleID` int(11) NOT NULL,
  `Available` binary(1) NOT NULL DEFAULT '0',
  `MakeYear` int(11) NOT NULL,
  `Type` varchar(12) NOT NULL,
  `Model` varchar(7) NOT NULL,
  `DailyRate` float(6,2) DEFAULT 0.00,
  `WeeklyRate` float(6,2) DEFAULT 0.00
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `cars`
--

INSERT INTO `cars` (`VehicleID`, `Available`, `MakeYear`, `Type`, `Model`, `DailyRate`, `WeeklyRate`) VALUES
(1, 0x31, 2012, 'VAN', 'Toyota', 60.99, 460.99),
(2, 0x31, 2016, 'Compact', 'Kia', 70.99, 470.99),
(3, 0x31, 2023, 'Large', 'Honda', 80.99, 480.99),
(4, 0x31, 2013, 'SUV', 'Hyundai', 90.99, 490.99),
(5, 0x31, 2008, 'Truck', 'Chevy', 100.99, 500.99),
(6, 0x31, 2015, 'Medium', 'Ford', 110.99, 510.99),
(7, 0x31, 2010, 'Compact', 'Dodge', 120.99, 520.99),
(8, 0x31, 2019, 'Large', 'Tesla', 130.99, 530.99),
(9, 0x31, 2017, 'VAN', 'BMW', 140.99, 540.99),
(10, 0x31, 2014, 'Truck', 'GM', 150.99, 550.99),
(11, 0x31, 2014, 'Medium', 'Cadilla', 160.99, 560.99),
(12, 0x31, 2014, 'SUV', 'Nissan', 170.99, 570.99),
(13, 0x31, 2014, 'SUV', 'Buick', 180.99, 580.99),
(14, 0x31, 2014, 'VAN', 'Mazda', 190.99, 590.99),
(15, 0x31, 2014, 'Compact', 'Lexus', 200.99, 600.99),
(16, 0x31, 2014, 'Truck', 'VW', 210.99, 610.99),
(17, 0x31, 2014, 'Large', 'Porsche', 220.99, 620.99),
(18, 0x31, 2014, 'Medium', 'Audi', 230.99, 630.99),
(19, 0x31, 2014, 'Truck', 'Jaguar', 240.99, 640.99),
(20, 0x31, 2014, 'SUV', 'Benz', 250.99, 650.99);

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `IDNo` int(11) NOT NULL,
  `FInit` char(1) DEFAULT NULL,
  `LName` varchar(12) DEFAULT NULL,
  `Phone` varchar(12) DEFAULT '000-000-0000'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`IDNo`, `FInit`, `LName`, `Phone`) VALUES
(1, 'N', 'Tyson', '123-456-7890'),
(2, 'J', 'Simmons', '098-765-4321'),
(3, 'R', 'Reanolds', '111-111-1111'),
(4, 'J', 'Black', '555-555-5555'),
(5, 'D', 'Johnson', '999-999-9999'),
(6, 'C', 'Pratt', '456-283-3845'),
(7, 'S', 'Buscemi', '374-239-5765'),
(8, 'T', 'Odinson', '444-444-4444'),
(9, 'G', 'Krovi', '435-283-4855'),
(10, 'D', 'Planet', '374-199-3845');

-- --------------------------------------------------------

--
-- Table structure for table `rental`
--

CREATE TABLE `rental` (
  `VehicleID` int(11) NOT NULL,
  `IDNo` int(11) NOT NULL,
  `StartDate` date NOT NULL,
  `Daily` binary(1) NOT NULL DEFAULT '0',
  `NumDays` int(11) NOT NULL DEFAULT 0,
  `ReturnDate` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `cars`
--
ALTER TABLE `cars`
  ADD PRIMARY KEY (`VehicleID`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`IDNo`);

--
-- Indexes for table `rental`
--
ALTER TABLE `rental`
  ADD PRIMARY KEY (`VehicleID`,`StartDate`),
  ADD KEY `IDNo` (`IDNo`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `rental`
--
ALTER TABLE `rental`
  ADD CONSTRAINT `rental_ibfk_1` FOREIGN KEY (`VehicleID`) REFERENCES `cars` (`VehicleID`),
  ADD CONSTRAINT `rental_ibfk_2` FOREIGN KEY (`IDNo`) REFERENCES `customer` (`IDNo`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
