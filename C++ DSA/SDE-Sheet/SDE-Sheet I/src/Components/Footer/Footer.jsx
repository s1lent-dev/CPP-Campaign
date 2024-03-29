import React from "react";
import "./styles.scss";
import ContentWrapper from "../ContentWrapper/ContentWrapper";
import logo from "../../assets/Dsaz logo.svg";
import YouTubeIcon from "@mui/icons-material/YouTube";
import InstagramIcon from "@mui/icons-material/Instagram";
import XIcon from "@mui/icons-material/X";
import FacebookIcon from "@mui/icons-material/Facebook";
import LinkedInIcon from "@mui/icons-material/LinkedIn";
import Github from "../../assets/github.png";
import leetcode from "../../assets/leetcode.svg";
import gfg from "../../assets/gfg.png";
import codechef from "../../assets/codechef1.jpg";
const Footer = () => {
  return (
    <div className="Footer">
      <ContentWrapper>
        <div className="container">
          <div className="top">
            <div className="left">
              <div className="logo">
                <img src={logo} alt="" />
              </div>
              <span className="desc">
                The best place to learn data structures, algorithms, most asked
                coding interview questions, real interview experiences free of
                cost.
              </span>
              <div className="contacts">
                <h4>Follow Us</h4>
                <div className="icons">
                  <a href="">
                    {" "}
                    <YouTubeIcon />{" "}
                  </a>
                  <a href="">
                    {" "}
                    <FacebookIcon />{" "}
                  </a>
                  <a href="">
                    {" "}
                    <InstagramIcon />{" "}
                  </a>
                  <a href="">
                    {" "}
                    <XIcon />{" "}
                  </a>
                  <a href="">
                    {" "}
                    <LinkedInIcon />{" "}
                  </a>
                </div>
              </div>
            </div>
            <div className="right">
              <div className="links">
                <h4>DSA Sheets</h4>
                <ul>
                  <li>DSA Sheet I</li>
                  <li>SDE Sheet I</li>
                  <li>SDE Sheet II</li>
                  <li>CP Sheet</li>
                </ul>
              </div>
              <div className="links">
                <h4>My Profiles</h4>
                <ul>
                  <li>
                    {" "}
                    <img src={Github} alt="" /> Github
                  </li>
                  <li>
                    <img src={leetcode} alt="" /> Leetcode
                  </li>
                  <li>
                    {" "}
                    <img src={gfg} alt="" />
                    GeeksforGeeks
                  </li>
                  <li>
                    <img src={codechef} alt="" />
                    Codechef
                  </li>
                </ul>
              </div>
              <div className="links">
                <h4>Contribute</h4>
                <span>Write Article</span>
              </div>
            </div>
          </div>
          <div className="line" />
          <div className="bottom">
            <h4>Copyright © 2024 DSAZ. All rights reserved</h4>
          </div>
        </div>
      </ContentWrapper>
    </div>
  );
};

export default Footer;
