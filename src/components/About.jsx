function About() {
    return(
       <section className="max-w-6x1 mx-auto px-6 py-24">
        <h2 className="text-5x1 font-black text-center mb-16">
            About Me
        </h2>
        <div className="grid md:grid-cols-3 gap-8">
            <div className="md:col-span-2 rounded-3x1 bg-white/5 backdrop-blur-md border border =-white/10 p-8">
                <h3 className="text-2x1 font-bold mb-6">
                    My Story
                </h3>
                <p className="text-gray-300 leading-8">
                    I'm a Computer science student with passion for building modern web applications and exploring new technologies.
                    I enjoy solving problems through code and continously improving my skills one project at a time.
                </p>
                <div className="rounded-3x1 bg-white/5 backdrop-blur-md border border-white/10 p-8">
                    <h3 className="text-2x1 font-bold mb-6">
                        Quick Facts
                    </h3>
                    <ul className="space-y-4">
                        <li>University of Malawi</li>
                        <li>Learning React and Tailwindcss</li>
                        <li>Malawi</li>
                        <li>Open to opportunities</li>
                    </ul>
                </div>
            </div>
        </div>
       </section> 
    );
}
export default About;