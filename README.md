# Obsidian - Security Audit, Vulnerability Remediation and Unit Testing 
An end-to-end cybersecurity project featuring a Black-box and White-box security audit, vulnerability assessment, C patch implementations, and automated unit testing.

## Project Context and Methodology
This project simulates a real-world security assessment scenario split into distinct phases:
1. **Black-Box Audit:** evaluated the provided compiled binary (`obsidian`) without source code access using reverse engineering tools, manual fuzzing, and string extraction.
2. **White-box Audit:** reviewed partial source code to identify deep memory safety issues, logic flaws and privilege escalation paths.
3. **Remediation and Patching:** developed targeted C source code patches (`.patch` files) to eliminate identified vulnerabilities.
4. **Automated Testing:** built unit tests using **Criterion** testing framework to verify that security patches resolve vulnerabilities.

## Repository Structure
- **`Final-report.pdf`:** the full, comprehensive security audit report documenting all discovered vulnerabilities, step-by-step exploit proofs (PoCs) and security fixes.
- **`Report-black-box.pdf`:** detailed report focusing on analyzing the executable, unpacking the binary (UPX) and finding initial vulnerabilities without source code.
- **`Report-white-box.pdf`:** source code analysis focused on memory safety errors (buffer overflows, UAF), logic flaws and format string bugs.
- **`fixes/`:** collection of C patch files written to fix the discovered security flaws.
- **`tests/`:** automated unit tests written with the **Criterion** framework to make sure the patches work correctly and securely.